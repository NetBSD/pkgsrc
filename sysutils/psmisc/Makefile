# $NetBSD: Makefile,v 1.19 2004/04/24 22:46:12 jlam Exp $

DISTNAME=		psmisc-20.1
CATEGORIES=		sysutils
PKGREVISION=		1
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=psmisc/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://psmisc.sourceforge.net/
COMMENT=		Miscellaneous procfs tools: killall, pidof, and pstree

CONFLICTS+=		pstree<=2.16

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		# defined
LIBS+=			${LIBGETOPT}

# "make install" doesn't install the link from killall -> pidof.
post-install:
	${RM} -f ${PREFIX}/bin/pidof
	${LN} -f ${PREFIX}/bin/killall ${PREFIX}/bin/pidof

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
