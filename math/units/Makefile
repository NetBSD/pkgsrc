# $NetBSD: Makefile,v 1.4 2012/05/29 18:33:34 cheusov Exp $

DISTNAME=	units-1.86
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=units/}

MAINTAINER=	cameron@patrick.wattle.id.au
HOMEPAGE=	http://www.gnu.org/software/units/
COMMENT=	GNU Units - a calculator capable of performing unit conversions

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=	gnu-gpl-v2

INFO_FILES=	YES

GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS=		--program-prefix=g

INSTALLATION_DIRS=	gnu/bin

post-install:
	set -e; cd ${DESTDIR}${PREFIX}/gnu/bin; \
	ln -s ../../bin/gunits units

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
