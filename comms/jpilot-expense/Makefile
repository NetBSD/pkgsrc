# $NetBSD: Makefile,v 1.9 2002/09/10 16:06:35 wiz Exp $

DISTNAME=		jpilot-0.99
PKGNAME=		jpilot-expense-0.99
PKGREVISION=		1
WRKSRC=			${WRKDIR}/${DISTNAME}/Expense
CATEGORIES=		comms
MASTER_SITES=		http://jpilot.org/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://jpilot.org/
COMMENT=		Expense synchronization plugin for J-Pilot

DEPENDS+=		jpilot>=0.99:../../comms/jpilot

USE_BUILDLINK_ONLY=	# defined
USE_LIBTOOL=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-gtk-prefix="${BUILDLINK_DIR}"
CONFIGURE_ARGS+=	--with-pilot-prefix="${BUILDLINK_DIR}"

PLUGINSDIR=		${PREFIX}/lib/jpilot/plugins
PLIST_SUBST+=		PLUGINSDIR=${PLUGINSDIR:S/${PREFIX}\///}

post-extract:
	${RM} -f ${WRKSRC}/../libtool
	${LN} -sf ${LIBTOOL} ${WRKSRC}/../libtool

.include "../../comms/jpilot/buildlink.mk"
.include "../../comms/pilot-link-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
