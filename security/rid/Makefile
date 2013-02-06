# $NetBSD: Makefile,v 1.16 2013/02/06 19:31:05 jperkin Exp $
#

DISTNAME=	rid-1.11
PKGREVISION=	2
CATEGORIES=	security net
MASTER_SITES=	http://www.theorygroup.com/Software/RID/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.theorygroup.com/Software/RID/
COMMENT=	Remote Intrusion Detection to track down compromised hosts

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	YES
USE_TOOLS+=	yacc lex

CONF_FILES=	${PREFIX}/share/examples/rid/rid.conf ${PKG_SYSCONFDIR}/rid.conf

INSTALLATION_DIRS=	sbin share/doc/rid share/examples/rid

post-configure:
	@echo "#undef DEFAULT_YYIN" >> ${WRKSRC}/netconfig.h
	@echo "#define DEFAULT_YYIN \"${PKG_SYSCONFDIR}/rid.conf\"" >> \
		${WRKSRC}/netconfig.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rid ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/BUGS ${WRKSRC}/CHANGES \
		${WRKSRC}/COPYRIGHT ${WRKSRC}/CREDITS ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/rid
	${INSTALL_DATA} ${WRKSRC}/rid.conf ${DESTDIR}${PREFIX}/share/examples/rid

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
