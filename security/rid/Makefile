# $NetBSD: Makefile,v 1.5 2003/09/23 13:15:17 jmmv Exp $
#

DISTNAME=	rid-1.11
PKGREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://www.theorygroup.com/Software/RID/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.theorygroup.com/Software/RID/
COMMENT=	Remote Intrusion Detection to track down compromised hosts

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES

CONF_FILES=	${PREFIX}/share/examples/rid/rid.conf ${PKG_SYSCONFDIR}/rid.conf

post-configure:
	@echo "#undef DEFAULT_YYIN" >> ${WRKSRC}/netconfig.h
	@echo "#define DEFAULT_YYIN \"${PKG_SYSCONFDIR}/rid.conf\"" >> \
		${WRKSRC}/netconfig.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rid ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rid
	${INSTALL_DATA} ${WRKSRC}/BUGS ${WRKSRC}/CHANGES \
		${WRKSRC}/COPYRIGHT ${WRKSRC}/CREDITS ${WRKSRC}/README \
		${PREFIX}/share/doc/rid
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/rid
	${INSTALL_DATA} ${WRKSRC}/rid.conf ${PREFIX}/share/examples/rid

.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
