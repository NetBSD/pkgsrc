# $NetBSD: Makefile,v 1.9 2019/06/28 20:17:35 bacon Exp $

DISTNAME=	ncbi-blast-2.8.1+-src
PKGNAME=	${DISTNAME:S/+-src//:S/blast/blast+/}
PKGREVISION=	3
CATEGORIES=	biology
MASTER_SITES=	https://ftp.ncbi.nlm.nih.gov/blast/executables/blast+/LATEST/ \
		https://ftp.ncbi.nlm.nih.gov/blast/executables/blast+/${PKGVERSION_NOREV}/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://blast.ncbi.nlm.nih.gov/
COMMENT=	NCBI implementation of Basic Local Alignment Search Tool
LICENSE=	public-domain

# Fix "undefined _ThreadRuneLocale" error on FreeBSD 10.0
# Fix "unknown options" in configure
SUBST_CLASSES+=		configure
SUBST_STAGE.configure=	pre-configure
SUBST_SED.configure+=	-e 's|-D_THREAD_SAFE|-D_THREAD_SAFE -D__RUNETYPE_INTERNAL|'
SUBST_SED.configure+=	-e '/--infodir=DIR/d'
SUBST_SED.configure+=	-e '/--mandir=DIR/d'
SUBST_FILES.configure+=	${WRKSRC}/src/build-system/configure

USE_TOOLS+=	bash gmake perl
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
GNU_CONFIGURE_STRICT=	no	# doesn't know --enable-option-checking
REPLACE_BASH=	scripts/common/impl/define_random_macros.sh
REPLACE_BASH+=	src/app/blast/get_species_taxids.sh
REPLACE_PERL=	src/app/blast/legacy_blast.pl src/app/blast/update_blastdb.pl
REPLACE_PYTHON=	src/app/winmasker/windowmasker_2.2.22_adapter.py

# The test for amq can hang, but amq is not needed so just avoid the test
# configure chooses /usr/local/bin/ar with no flags
# Resolve a conflict with libproj by moving libs to a subdir
CONFIGURE_ENV=		ncbi_cv_prog_amq_w=no
CONFIGURE_ARGS+=	AR="ar cr" --without-boost
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/ncbi-tools++
WRKSRC=			${WRKDIR}/${DISTNAME}/c++

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == NetBSD
# statfs is deprecated on NetBSD, but still exists in libc
# configure checks only for undefined reference, not for usability
CONFIGURE_ENV+=		ac_cv_func_statfs=no
.endif

post-install:
	${RM} ${DESTDIR}${PREFIX}/include/ncbi-tools++/*/*/.cvsignore.extra
	${STRIP} ${DESTDIR}${PREFIX}/lib/ncbi-tools++/*.so

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
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
