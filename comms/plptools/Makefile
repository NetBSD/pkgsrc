# $NetBSD: Makefile,v 1.8 2000/06/12 14:30:53 skrll Exp $
#

DISTNAME=	plptools-0.6
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.to.com/pub/psion/tarballs/

MAINTAINER=	sakamoto@netbsd.org

DEPENDS=	readline-4.0:../../devel/readline

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		CPPFLAGS="-I${PREFIX}/include/" LIBS="-ltermlib"

.include "../../mk/bsd.pkg.mk"
