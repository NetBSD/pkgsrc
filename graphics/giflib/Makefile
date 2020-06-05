# $NetBSD: Makefile,v 1.56 2020/06/05 12:48:59 jperkin Exp $

.include "Makefile.common"
PKGREVISION=	4

COMMENT=	GIF image format library

CONFLICTS+=	libungif-[0-9]*

# clang: error: no such file or directory: 'dgif_lib.o'
# clang: error: no such file or directory: 'egif_lib.o'
MAKE_JOBS_SAFE=		no

INSTALL_TARGET=		install-include
INSTALL_TARGET+=	install-lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
.  for lib in libgif.7.2.0.dylib
	install_name_tool -id ${PREFIX}/lib/${lib} ${DESTDIR}${PREFIX}/lib/${lib}
.  endfor
.endif

.include "../../mk/bsd.pkg.mk"
