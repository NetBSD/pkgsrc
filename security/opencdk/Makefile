# $NetBSD: Makefile,v 1.27 2007/06/15 22:42:33 wiz Exp $

DISTNAME=	opencdk-0.6.4
CATEGORIES=	security devel
MASTER_SITES=	http://www.stud.uni-hannover.de/~twoaday/opencdk/ \
		http://josefsson.org/gnutls/releases/opencdk/ \
		ftp://ftp.gnutls.org/pub/gnutls/opencdk/ \
		http://www.gnu.org/software/gnutls/releases/opencdk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	Open Crypto Development Kit

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check

NOT_FOR_COMPILER=	xlc

REPLACE_PERL=		doc/gdoc

DOCDIR=		${PREFIX}/share/doc/opencdk
EGDIR=		${PREFIX}/share/examples/opencdk
HTMLDIR=	${PREFIX}/share/doc/html/opencdk

PKGCONFIG_OVERRIDE=	src/opencdk.pc.in

INSTALLATION_DIRS=	${DOCDIR} ${HTMLDIR} ${EGDIR}

pre-install:
	${INSTALL_DATA}	${WRKSRC}/doc/opencdk-api.html ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/tests && ${INSTALL_DATA} *.gpg *.c ${DESTDIR}${EGDIR}

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgcrypt+=	libgcrypt>=1.2.2
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
