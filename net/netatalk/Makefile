# $NetBSD: Makefile,v 1.13 2001/11/29 01:12:43 hubertf Exp $
#

DISTNAME=		netatalk-990130
PKGNAME=		netatalk-umich-19990130
PKGREVISION=		2
WRKSRC=			${WRKDIR}/netatalk-990130
CATEGORIES=		net
MASTER_SITES=		ftp://terminator.rs.itd.umich.edu/unix/netatalk/

MAINTAINER=		wrstuden@netbsd.org
HOMEPAGE=		http://www.umich.edu/~rsug/netatalk/
COMMENT=		University of Michigan's netatalk; AppleTalk interworking

CONFLICTS=		netatalk-asun-[0-9]*
CONFLICTS+=		netatalk-19981109

do-configure:
	${CP} ${FILESDIR}/shlib_version ${WRKSRC}/libatalk

post-install:
	${RM} ${PREFIX}/share/examples/netatalk/AppleVolumes.system.orig
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
