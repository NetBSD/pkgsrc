# $NetBSD: Makefile,v 1.7 2000/08/06 19:21:29 jlam Exp $
#

DISTNAME=		netatalk-990130
PKGNAME=		netatalk-19990130
WRKSRC=			${WRKDIR}/netatalk-990130
CATEGORIES=		net
MASTER_SITES=		ftp://terminator.rs.itd.umich.edu/unix/netatalk/

MAINTAINER=		wrstuden@netbsd.org
HOMEPAGE=		http://www.umich.edu/~rsug/netatalk/

CONFLICTS=		netatalk-asun-[0-9]*
CONFLICTS+=		netatalk-19981109

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
