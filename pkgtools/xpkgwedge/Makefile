# $NetBSD: Makefile,v 1.6 1998/07/31 19:30:49 tv Exp $
#

DISTNAME=	xpkgwedge-0.4
CATEGORIES=	devel x11
DISTFILES=	# none

MAINTAINER=	tv@netbsd.org

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_IMAKE=	yes

# In order to force xpkgwedge to install into X11BASE, we forcibly set PREFIX
# here.  No other pkg should do this.
PREFIX=${X11BASE}

pre-extract:
	@if [ ! -f ${X11BASE}/include/X11/X.h ]; then \
		${ECHO} 'xpkgwedge requires $$X11BASE to point to the real X distribution.'; \
		${ECHO} 'If you are setting this variable in mk.conf, fix or remove the setting'; \
		${ECHO} 'and then install xpkgwedge.'; \
		${FALSE}; \
	fi

pre-configure:
	@${CP} ${FILESDIR}/Imakefile ${FILESDIR}/xpkgwedge.def ${WRKSRC}

pre-install:
	@${SED} -e 's|@@PREFIX@@|${LOCALBASE}|g' < ${PKGDIR}/MESSAGE.pre \
		> ${PKGDIR}/MESSAGE

pre-clean:
	@${RM} ${PKGDIR}/MESSAGE

.include "../../mk/bsd.pkg.mk"

# Clear the build dependencies list so that xpkgwedge will not be recursively
# dependent on itself.
BUILD_DEPENDS=
