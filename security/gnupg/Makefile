# $NetBSD: Makefile,v 1.70 2004/10/03 00:18:08 tv Exp $

DISTNAME=	gnupg-1.2.6
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gnupg/ \
		ftp://ftp.planetmirror.com/pub/gnupg/gnupg/ \
		ftp://gd.tuwien.ac.at/privacy/gnupg/gnupg/ \
		ftp://ftp.jyu.fi/pub/crypt/gcrypt/gnupg/ \
		ftp://ftp.freenet.de/pub/ftp.gnupg.org/gcrypt/gnupg/
EXTRACT_SUFX=	.tar.bz2
# don't remove this -- we may add idea.c.gz to it below
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnupg.org/
COMMENT=	Privacy Guard, public-Key encryption and digital signatures

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_USES_MSGFMT=	yes
CRYPTO=			yes
GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
CONFIGURE_ARGS+=	--enable-tiger --with-static-rnd=auto
CONFIGURE_ARGS+=	--with-mailprog=/usr/sbin/sendmail
TEST_TARGET=		check

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

INFO_FILES=	gpg.info gpgv.info

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	USE_I586 USE_IDEA USE_OPENLDAP M68060

.if defined(USE_I586) && ${USE_I586} == YES
# use assembler routines optimized for i586
ONLY_FOR_PLATFORM=	*-*-i386
MACHINE_GNU_ARCH=	i586
.endif

.if defined(M68060) && ${M68060} == YES
# be more efficient on M68060 machines
CONFIGURE_ENV+=                M68060=${M68060}
CFLAGS+=                       -m68060
.endif

.if defined(USE_IDEA) && ${USE_IDEA} == YES
# use of IDEA as crypto function
LICENCE=	fee-based-commercial-use
DISTFILES+=	idea.c.gz
SITES_idea.c.gz=ftp://ftp.gnupg.dk/pub/contrib-dk/ \
		http://www.gnupg.dk/contrib-dk/

INSTALLATION_DIRS=	bin libexec/gnupg man/man1 man/man7 share/gnupg

pre-configure:
	${GZCAT} ${DISTDIR}/idea.c.gz > ${WRKSRC}/cipher/idea.c
.endif

.if defined(USE_OPENLDAP) && ${USE_OPENLDAP} == YES
.include "../../databases/openldap/buildlink3.mk"
PLIST_SUBST+=	OPENLDAP=""
.else
CONFIGURE_ARGS+=--disable-ldap
PLIST_SUBST+=	OPENLDAP="@comment "
.endif

.if ${OPSYS} == "FreeBSD"

SUBST_CLASSES=	    fixme
SUBST_STAGE.fixme=  post-configure
SUBST_FILES.fixme=  mpi/i386/mpih-add1.S mpi/i386/mpih-lshift.S \
		    mpi/i386/mpih-mul1.S mpi/i386/mpih-mul2.S \
		    mpi/i386/mpih-mul3.S mpi/i386/mpih-rshift.S \
		    mpi/i386/mpih-sub1.S
SUBST_SED.fixme=    -e "s,ALIGN (3),ALIGN (4),g"

.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/DETAILS \
	    ${PREFIX}/share/gnupg

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
