# $NetBSD: Makefile,v 1.10 2002/09/21 07:24:04 jlam Exp $

DISTNAME=		jpilot-0.99
PKGNAME=		jpilot-expense-0.99
PKGREVISION=		1
WRKSRC=			${WRKDIR}/${DISTNAME}/Expense
CATEGORIES=		comms
MASTER_SITES=		http://jpilot.org/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://jpilot.org/
COMMENT=		Expense synchronization plugin for J-Pilot

BUILDLINK_DEPMETHOD.jpilot=	full

USE_BUILDLINK2=		# defined
USE_X11=		# defined
USE_LIBTOOL=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-gtk-prefix="${BUILDLINK_PREFIX.gtk}"
CONFIGURE_ARGS+=	--with-pilot-prefix="${BUILDLINK_PREFIX.pilot-link-libs}"

PLUGINSDIR=		${PREFIX}/lib/jpilot/plugins
PLIST_SUBST+=		PLUGINSDIR=${PLUGINSDIR:S/${PREFIX}\///}

post-extract:
	${RM} -f ${WRKSRC}/../libtool
	${LN} -sf ${PKGLIBTOOL} ${WRKSRC}/../libtool

.include "../../comms/jpilot/buildlink2.mk"
.include "../../comms/pilot-link-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
