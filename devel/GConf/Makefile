# $NetBSD: Makefile,v 1.1.1.1 2000/08/30 06:19:08 rh Exp $
#

DISTNAME=	GConf-0.8
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/GConf/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://advogato.org/proj/GConf/

DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core
DEPENDS+=	oaf-*:../../devel/oaf
DEPENDS+=	guile>=1.3.4:../../lang/guile

MESSAGE_FILE=	${WRKDIR}/MESSAGE

.include "../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} != "ELF"
BROKEN=		"GConf only builds correctly on ELF architectures"
.endif

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${X11PREFIX}/include"

post-install:
	${SED} -e 's#@@X11PREFIX@@#${X11PREFIX}#g' < ${PKGDIR}/MESSAGE \
		> ${MESSAGE_FILE}

.include "../../mk/bsd.pkg.mk"
