# $NetBSD: Makefile,v 1.10 2009/05/19 08:59:24 wiz Exp $

DISTNAME=	sch-20010224
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.itojun.org/pub/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Curses-based schedule management tool
LICENSE=	no-commercial-use

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/sch/build
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin

# manpages are not complete, don't confuse people
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sch ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
