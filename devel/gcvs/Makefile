# $NetBSD: Makefile,v 1.1.1.1 2001/06/24 23:11:42 zuntum Exp $

DISTNAME=		gcvs-1.0a7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cvsgui/}

MAINTAINER=		mike@ethmoid.org
HOMEPAGE=		http://cvsgui.sourceforge.net/
COMMENT=		GTK interface for CVS

CONFLICTS=		cvs-[0-9]*

USE_BUILDLINK_ONLY=	yes
USE_X11=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-tclinclude="${BUILDLINK_DIR}/include"	\
			--with-tcllib="${BUILDLINK_DIR}/lib"		\
			--with-gtk-prefix="${BUILDLINK_DIR}"

post-patch:
	${SED} "s,-ltcl,-ltcl83," ${WRKSRC}/configure > ${WRKSRC}/configure.done
	${MV} -f ${WRKSRC}/configure.done ${WRKSRC}/configure
	${CHMOD} +x ${WRKSRC}/configure

.include "../../lang/tcl/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
