# $NetBSD: Makefile,v 1.43 2024/05/29 16:31:27 adam Exp $

DISTNAME=	ncbi-blast-2.14.1+-src
PKGNAME=	${DISTNAME:S/+-src//:S/blast/blast+/}
PKGREVISION=	4
CATEGORIES=	biology
MASTER_SITES=	https://ftp.ncbi.nlm.nih.gov/blast/executables/blast+/LATEST/ \
		https://ftp.ncbi.nlm.nih.gov/blast/executables/blast+/${PKGVERSION_NOREV}/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://blast.ncbi.nlm.nih.gov/
COMMENT=	NCBI implementation of Basic Local Alignment Search Tool
LICENSE=	public-domain

USE_CXX_FEATURES=	c++17

# Nobody does bioinformatics on 32-bit processors anymore
ONLY_FOR_PLATFORM=	${LP64PLATFORMS}

# Fix "undefined _ThreadRuneLocale" error on FreeBSD 10.0
# Fix "unknown options" in configure
SUBST_CLASSES+=		configure
SUBST_STAGE.configure=	pre-configure
SUBST_SED.configure+=	-e 's|-D_THREAD_SAFE|-D_THREAD_SAFE -D__RUNETYPE_INTERNAL|'
SUBST_SED.configure+=	-e '/--infodir=DIR/d'
SUBST_SED.configure+=	-e '/--mandir=DIR/d'
SUBST_FILES.configure+=	src/build-system/configure

USE_TOOLS+=		bash gmake perl
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no	# doesn't know --enable-option-checking
REPLACE_BASH=		scripts/common/impl/define_random_macros.sh
REPLACE_BASH+=		src/app/blast/get_species_taxids.sh
REPLACE_PERL=		src/app/blast/legacy_blast.pl src/app/blast/update_blastdb.pl
REPLACE_PYTHON=		src/app/winmasker/windowmasker_2.2.22_adapter.py
REPLACE_PYTHON+=	src/app/blast/cleanup-blastdb-volumes.py
MKPIE_SUPPORTED=	no	# Temporary fix

# The test for amq can hang, but amq is not needed so just avoid the test
# configure chooses /usr/local/bin/ar with no flags
# Resolve a conflict with libproj by moving libs to a subdir
CONFIGURE_ENV=		ncbi_cv_prog_amq_w=no
CONFIGURE_ARGS+=	AR="ar cr" --without-boost
# pkglint warning, but build fails on NetBSD without it
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/ncbi-tools++
WRKSRC=			${WRKDIR}/${DISTNAME}/c++

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == NetBSD
# statfs is deprecated on NetBSD, but still exists in libc
# configure checks only for undefined reference, not for usability
CONFIGURE_ENV+=		ac_cv_func_statfs=no
.endif

.if ${OPSYS} == Darwin
CONFIGURE_ARGS+=	--without-openmp
.endif

# c++/src/objtools/edit/seq_entry_edit.cpp: In member function 'void ncbi::objects::edit::{anonymous}::CSeqdescSortMap::Init()':
# c++/src/objtools/edit/seq_entry_edit.cpp:172:44: error: array subscript has type 'char' [-Werror=char-subscripts]
#              while (descr_insert_order[index] != 0)
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

post-install:
	${FIND} ${DESTDIR}${PREFIX} -name '\.cvs*' -exec rm -rf '{}' \;
	${FIND} ${DESTDIR}${PREFIX} -name '\.subversion*' -exec rm -rf '{}' \;
	${FIND} ${DESTDIR}${PREFIX} -name '\.git*' -exec rm -rf '{}' \;
.if ${OPSYS} != Darwin
	${STRIP} ${DESTDIR}${PREFIX}/lib/ncbi-tools++/*.so
	${RM} -rf ${WRKDIR}/.home
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../databases/lmdb/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libidn2/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.include "../../security/p11-kit/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
