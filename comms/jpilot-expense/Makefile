# $NetBSD: Makefile,v 1.1.1.1 2001/03/01 20:39:31 jlam Exp $

DISTNAME=		jpilot-0.99
PKGNAME=		jpilot-expense-0.99
WRKSRC=			${WRKDIR}/${DISTNAME}/Expense
CATEGORIES=		comms
MASTER_SITES=		http://jpilot.org/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://jpilot.org/
COMMENT=		Expense synchronization plugin for J-Pilot

DEPENDS+=		jpilot>=0.99:../../comms/jpilot

USE_X11=		# defined
USE_LIBTOOL=		# defined

GNU_CONFIGURE=		# defined
EVAL_PREFIX+=		GTKDIR=gtk+
EVAL_PREFIX+=		PILOTLINKDIR=pilot-link
CONFIGURE_ARGS+=	--with-gtk-prefix="${GTKDIR}"
CONFIGURE_ARGS+=	--with-pilot-prefix="${PILOTLINKDIR}"

PLUGINSDIR=		${PREFIX}/lib/jpilot/plugins
PLIST_SUBST+=		PLUGINSDIR=${PLUGINSDIR:S/${PREFIX}\///}

post-extract:
	${RM} -f ${WRKSRC}/../libtool
	${LN} -sf ${LIBTOOL} ${WRKSRC}/../libtool

.include "../../mk/bsd.pkg.mk"
