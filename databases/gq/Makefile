# $NetBSD: Makefile,v 1.9 2003/05/02 11:54:11 wiz Exp $
#

DISTNAME=	gq-0.3.0
PKGREVISION=	2
CATEGORIES=	databases net
MASTER_SITES=	http://biot.com/gq/download/ \
		${MASTER_SITE_SOURCEFORGE:=gqclient/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://biot.com/gq/
COMMENT=	GTK-based LDAP client

DEPENDS+=	gnome1-dirs>=1.0:../../misc/gnome1-dirs

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

.include "../../databases/openldap/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
