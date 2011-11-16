# $NetBSD: Makefile,v 1.109 2011/11/16 08:23:49 sbd Exp $

DISTNAME=	gnupg-1.4.11
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gnupg/ \
		http://gd.tuwien.ac.at/privacy/gnupg/gnupg/ \
		ftp://ftp.jyu.fi/pub/crypt/gcrypt/gnupg/ \
		ftp://ftp.ring.gr.jp/pub/net/gnupg/gnupg/
EXTRACT_SUFX=	.tar.bz2
# don't remove this -- we may add idea.c.gz to it in options.mk
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnupg.org/
COMMENT=	GNU Privacy Guard, public-Key encryption and digital signatures
LICENSE=	gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

CRYPTO=			yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
CONFIGURE_ARGS+=	--with-static-rnd=auto
CONFIGURE_ARGS+=	--with-mailprog=/usr/sbin/sendmail
TEST_TARGET=		check
INFO_FILES=		yes

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

.include "options.mk"

.if ${OPSYS} == "SunOS" || (${OPSYS} == "NetBSD" && !empty(OS_VERSION:M1.[0-6]*))
CONFIGURE_ARGS+=	--disable-gnupg-iconv
.endif

.if (${OPSYS} == "AIX" || ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS") \
    && defined(ABI) && ${ABI} == 64
CONFIGURE_ARGS+=	--disable-asm
.endif

# XXX: still needed?
#.if ${OPSYS} == "FreeBSD"
#SUBST_CLASSES+=	    fixme
#SUBST_STAGE.fixme=  post-configure
#SUBST_FILES.fixme=  mpi/i386/mpih-add1.S mpi/i386/mpih-lshift.S \
#		    mpi/i386/mpih-mul1.S mpi/i386/mpih-mul2.S \
#		    mpi/i386/mpih-mul3.S mpi/i386/mpih-rshift.S \
#		    mpi/i386/mpih-sub1.S
#SUBST_SED.fixme=    -e "s,ALIGN (3),ALIGN (4),g"
#.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/DETAILS \
	    ${DESTDIR}${PREFIX}/share/gnupg

.include "../../devel/readline/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
