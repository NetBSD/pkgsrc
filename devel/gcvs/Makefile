# $NetBSD: Makefile,v 1.5 2001/10/23 13:14:50 jlam Exp $

DISTNAME=		gcvs-1.0a7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cvsgui/}

MAINTAINER=		mike@ethmoid.org
HOMEPAGE=		http://cvsgui.sourceforge.net/
COMMENT=		GTK interface for CVS

CONFLICTS=		cvs-[0-9]*

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-tclinclude="${BUILDLINK_DIR}/include"	\
			--with-tcllib="${BUILDLINK_DIR}/lib"

post-patch:
	${SED} "s,-ltcl,-ltcl83," ${WRKSRC}/configure > ${WRKSRC}/configure.done
	${MV} -f ${WRKSRC}/configure.done ${WRKSRC}/configure
	${CHMOD} +x ${WRKSRC}/configure

.include "../../mk/x11.buildlink.mk"
.include "../../lang/tcl/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
