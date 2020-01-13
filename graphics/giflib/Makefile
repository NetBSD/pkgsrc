# $NetBSD: Makefile,v 1.52 2020/01/13 07:20:17 minskim Exp $

.include "Makefile.common"
PKGREVISION=	1

COMMENT=	GIF image format library

CONFLICTS+=	libungif-[0-9]*

INSTALL_TARGET= 	install-include
INSTALL_TARGET+= 	install-lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
.  for lib in libgif.7.2.0.dylib libgifutil.dylib
	install_name_tool -id ${PREFIX}/lib/${lib} ${DESTDIR}${PREFIX}/lib/${lib}
.  endfor
.endif

.include "../../mk/bsd.pkg.mk"
