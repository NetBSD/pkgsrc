# $NetBSD: Makefile,v 1.20 2003/11/11 16:44:16 abs Exp $

DISTNAME=	rconfig-0.27
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mono.org/abs/tools/rconfig/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.mono.org/abs/tools/rconfig/
COMMENT=	Manage configurations for many machines via rdist trees

DEPENDS+=	fping-[0-9]*:../../net/fping
DEPENDS+=	freerdist-[0-9]*:../../net/rdist6
DEPENDS+=	srsh-[0-9]*:../../net/srsh

USE_PERL5=	# defined

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rconfig.pl ${PREFIX}/sbin/rconfig
	${INSTALL_SCRIPT} ${WRKSRC}/probe.sh ${PREFIX}/libexec/rconfig_probe
	${INSTALL_MAN} ${WRKSRC}/rconfig.8 ${PREFIX}/man/man8/rconfig.8

.include "../../mk/bsd.pkg.mk"
