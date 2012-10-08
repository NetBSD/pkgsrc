# $NetBSD: Makefile,v 1.17 2012/10/08 12:19:29 asau Exp $
#

DISTNAME=		qtools-0.56
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.superscript.com/qtools/
COMMENT=		Utilities for filtering via .qmail

DEPENDS+=		{ezmlm>=0.53,ezmlm-idx-[0-9]*}:../../mail/ezmlm
DEPENDS+=		qmail>=1.03:../../mail/qmail

DJB_RESTRICTED=		NO
DJB_CONFIG_CMDS=	${ECHO} ${LOCALBASE:Q} > ${WRKSRC}/conf-ezmlm

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
