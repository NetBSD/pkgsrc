# $NetBSD: Makefile,v 1.8 1999/12/05 15:22:13 tron Exp $
# FreeBSD Id: Makefile,v 1.6 1996/11/17 09:05:15 obrien Exp

DISTNAME=       buffer-1.17
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.gwdg.de/pub/linux/jurix/source/system/backup/ \
		ftp://ftp.fu-berlin.de/unix/linux/mirrors/jurix.jura.uni-sb.de/source/system/backup/

MAINTAINER=	tron@netbsd.org

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CPPFLAGS+=	-DSYS5
MAKE_ENV+=	CC="${CC}" CPPFLAGS="${CPPFLAGS}"
.endif

.include "../../mk/bsd.pkg.mk"
