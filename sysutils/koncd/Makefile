# $NetBSD: Makefile,v 1.1.1.1 2001/05/24 14:42:12 tron Exp $

DISTNAME=	koncd-0.7.1
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}download/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://www.koncd.de/
COMMENT=	Frontend to the fabulous cdrecord and mkisofs programs

BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf
BUILD_DEPENDS+=	automake-1.4:../../devel/automake
DEPENDS+=	cdrecord>=1.9:../../sysutils/cdrecord
DEPENDS+=	kdebase>=2.1:../../x11/kdebase2

.include	"../../x11/kde2/Makefile.part2"

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
