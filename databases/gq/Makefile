# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 18:07:07 rh Exp $
#

DISTNAME=	gq-0.3.0
CATEGORIES=	databases net
MASTER_SITES=	http://biot.com/gq/download/ \
		http://download.sourceforge.net/gqclient/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://biot.com/gq/

DEPENDS+=	openldap>=1.2.11:../../databases/openldap
DEPENDS+=	gtk+>=1.2.8:../../x11/gtk

USE_X11BASE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
