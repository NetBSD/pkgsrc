# $NetBSD: Makefile,v 1.3 2001/02/16 14:17:25 wiz Exp $
#

DISTNAME=	gq-0.3.0
CATEGORIES=	databases net
MASTER_SITES=	http://biot.com/gq/download/ \
		${MASTER_SITE_SOURCEFORGE:=gqclient/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://biot.com/gq/
COMMENT=	GTK-based LDAP client

DEPENDS+=	openldap>=1.2.11:../../databases/openldap
DEPENDS+=	gtk+>=1.2.8:../../x11/gtk

USE_X11BASE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
