# $NetBSD: Makefile,v 1.3 2013/12/02 10:11:39 wiz Exp $

DISTNAME=	realboy-0.2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=realboy/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://realboyemulator.wordpress.com/
COMMENT=	Complete, fast, yet accurate Game Boy/Game Boy Color emulator
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
INSTALLATION_DIRS=	share/doc/realboy

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/realboy

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
