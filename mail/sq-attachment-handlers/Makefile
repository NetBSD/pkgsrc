# $NetBSD: Makefile,v 1.1.1.1 2001/05/16 08:18:03 jlam Exp $

DISTNAME=	attachment_common.1.8-1.0.6
PKGNAME=	sq-attachment-handlers-1.8
WRKSRC=		${WRKDIR}/attachment_common
CATEGORIES=	mail
MASTER_SITES=	http://www.squirrelmail.org/plugins/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.squirrelmail.org/index.php3?page=15&plugin=attachment_common
COMMENT=	SquirrelMail attachment handler plugin

DEPENDS+=	squirrelmail>=1.0.6:../../mail/squirrelmail

SMDIR=		${PREFIX}/share/squirrelmail
MESSAGE_SUBST+=	SMDIR=${SMDIR}

NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:
	${CP} -R ${WRKSRC} ${SMDIR}/plugins

.include "../../mk/bsd.pkg.mk"
