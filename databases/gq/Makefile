# $NetBSD: Makefile,v 1.5 2001/10/27 15:20:40 kleink Exp $
#

DISTNAME=	gq-0.3.0
CATEGORIES=	databases net
MASTER_SITES=	http://biot.com/gq/download/ \
		${MASTER_SITE_SOURCEFORGE:=gqclient/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://biot.com/gq/
COMMENT=	GTK-based LDAP client

USE_BUILDLINK_ONLY=	YES

GNU_CONFIGURE=	YES

.include "../../databases/openldap/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
