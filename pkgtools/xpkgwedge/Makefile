# $NetBSD: Makefile,v 1.13 2000/06/28 15:02:32 agc Exp $
#

DISTNAME=	xpkgwedge-0.4
CATEGORIES=	pkgtools devel x11
DISTFILES=	# none

MAINTAINER=	tv@netbsd.org

NO_CHECKSUM=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_IMAKE=	yes

MESSAGE_FILE=	${WRKDIR}/MESSAGE

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
		> ${MESSAGE_FILE}

.include "../../mk/bsd.pkg.mk"

# In order to force xpkgwedge to install into X11BASE, we forcibly override
# the PREFIX definition.  _NO_ other pkg should do this.
PREFIX=${X11BASE}

# Clear the build dependencies list so that xpkgwedge will not be recursively
# dependent on itself.
BUILD_DEPENDS=
