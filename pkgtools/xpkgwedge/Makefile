# $NetBSD: Makefile,v 1.1 1998/06/26 16:39:23 tv Exp $
#

DISTNAME=	xpkgwedge-0.1
CATEGORIES=	devel x11
DISTFILES=	# none

MAINTAINER=	tv@netbsd.org

RESTRICTED=	optional	# NOT for distro as a "binary" pkg
IS_INTERACTIVE=	yes		# should not be built when batch

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_IMAKE=	yes

pre-extract:
	@if [ x${LOCALBASE} = x${X11BASE} ]; then \
		${ECHO} '$$LOCALBASE == $$X11BASE; this patch cannot be applied.'; \
		${ECHO} 'During install, xpkgwedge requires $$X11BASE to point to the real X distribution.'; \
		${ECHO} 'If you are setting this variable in mk.conf, remove the setting temporarily'; \
		${ECHO} 'and then install xpkgwedge.'; \
		${FALSE}; \
	fi

pre-configure:
	@${CP} ${FILESDIR}/Imakefile ${FILESDIR}/xpkgwedge.def ${WRKSRC}

post-install:
	@${SED} -e s,@@PREFIX@@,${LOCALBASE}, ${PKGDIR}/MESSAGE

.include "../../mk/bsd.pkg.mk"
