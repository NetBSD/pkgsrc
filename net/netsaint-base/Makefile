# $NetBSD: Makefile,v 1.11 2002/03/25 12:54:17 rh Exp $
#

DISTNAME=		netsaint-0.0.7
PKGNAME=		${DISTNAME:S/-/-base-/}
CATEGORIES=		net
MASTER_SITES=		http://www.netsaint.org/download/

MAINTAINER=		murray@river-styx.org
HOMEPAGE=		http://www.netsaint.org/
COMMENT=		network monitor

DEPENDS+=		gd>=1.8.4nb1:../../graphics/gd

.include "../../net/netsaint-base/Makefile.common"

INSTALL_TARGET=		install install-config

post-configure:
	${SED} <${FILESDIR}/netsaint-setup.sh >${WRKDIR}/netsaint-setup.sh	\
		-e 's:@@USER@@:${NETSAINT_USER}:g'	\
		-e 's:@@GROUP@@:${NETSAINT_GROUP}:g'

post-install:
	cd ${WRKDIR} && ${INSTALL_SCRIPT} netsaint-setup.sh ${PREFIX}/sbin;	\
	cd ${PREFIX}/etc/netsaint;	\
	${MV} commands.cfg commands.cfg.sample;	\
	${MV} hosts.cfg hosts.cfg.sample;	\
	${MV} netsaint.cfg netsaint.cfg.sample;	\
	${MV} nscgi.cfg nscgi.cfg.sample;	\
	${MV} resource.cfg resource.cfg.sample;	\
	${CHMOD} u+x *.sample

.include "../../mk/bsd.pkg.mk"
