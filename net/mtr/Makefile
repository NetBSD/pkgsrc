# $NetBSD: Makefile,v 1.5 2000/03/17 13:56:52 tron Exp $
# $FreeBSD: ports/net/mtr/Makefile,v 1.16 1999/10/28 08:06:00 mharo Exp $

DISTNAME=	mtr-0.41
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/ \
		http://www.giovannelli.it/~gmarco/files/

MAINTAINER=	sommerfeld@netbsd.org
HOMEPAGE=	http://www.bitwizard.nl/mtr/

# not needed in current as of some time before 1999/12/1, but 
# needed for 1.4.x, so just use ncurses..
DEPENDS+=	ncurses>=4.2:../../devel/ncurses

BUILD_DEFS=	USE_INET6
.include "../../mk/bsd.prefs.mk"
.if defined(USE_INET6) && ${USE_INET6} == "YES"
PATCHFILES=	mtr-041-v6-20000127a.diff.gz
PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCH_DIST_STRIP=	-p1
CONFIGURE_ARGS+=--enable-ipv6
.else
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} mtr-041-v6-20000127a.diff.gz
MASTER_SITES+=	ftp://ftp.kame.net/pub/kame/misc/
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV+= CPPFLAGS=-I${PREFIX}/include

do-install:
	${INSTALL} -c -s -m 4755 -o root -g wheel ${WRKSRC}/mtr ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/mtr.8 ${PREFIX}/man/man8

post-install:
	@${ECHO} ""
	@${ECHO} "${PREFIX}/sbin/mtr is setuid \"root\" "
	@${ECHO} ""
	@${ECHO} "Please read about potential security issues"
	@${ECHO} "in file ${WRKSRC}/SECURITY (not installed)"
	@${ECHO} ""

.include "../../mk/bsd.pkg.mk"
