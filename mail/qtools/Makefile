# $NetBSD: Makefile,v 1.12 2005/03/23 00:51:10 schmonz Exp $
#

DISTNAME=	qtools-0.56
CATEGORIES=	mail
MASTER_SITES=	http://www.superscript.com/qtools/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.superscript.com/qtools/intro.html
COMMENT=	Utilities for filtering via .qmail

DEPENDS+=	{ezmlm>=0.53,ezmlm-idx-[0-9]*}:../../mail/ezmlm
DEPENDS+=	qmail>=1.03:../../mail/qmail

USE_BUILDLINK3=	yes

DJB_RESTRICTED=	NO
DJB_CONFIG_CMDS=${ECHO} ${LOCALBASE} > ${WRKSRC}/conf-ezmlm

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
