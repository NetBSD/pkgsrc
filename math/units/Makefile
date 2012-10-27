# $NetBSD: Makefile,v 1.7 2012/10/27 11:50:42 wen Exp $

DISTNAME=	units-2.01
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=units/}

MAINTAINER=	cameron@patrick.wattle.id.au
HOMEPAGE=	http://www.gnu.org/software/units/
COMMENT=	GNU Units - a calculator capable of performing unit conversions
LICENSE=	gnu-gpl-v3

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
INFO_FILES=	yes

INSTALLATION_DIRS=	gnu/bin

REPLACE_PYTHON=	units_cur

post-install:
	set -e; cd ${DESTDIR}${PREFIX}/gnu/bin; \
	ln -s ../../bin/gunits units

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
