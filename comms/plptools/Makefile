# $NetBSD: Makefile,v 1.11 2001/04/05 01:48:31 dmcmahill Exp $
#

DISTNAME=	plptools-0.6
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.to.com/pub/psion/tarballs/

MAINTAINER=	sakamoto@netbsd.org
COMMENT=	FTP-like and NFS-like access tools to talk to the PSION

DEPENDS=	readline>=4.0:../../devel/readline

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		CPPFLAGS="-I${PREFIX}/include/" LIBS="-ltermlib"

.include "../../mk/bsd.prefs.mk"
CONFIGURE_ARGS+=	--with-serial=${DEFAULT_SERIAL_DEVICE}

.include "../../mk/bsd.pkg.mk"
