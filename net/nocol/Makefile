# $NetBSD: Makefile,v 1.1 1998/07/24 13:36:52 agc Exp $
#

DISTNAME=	nocol-4.2beta6
PKGNAME=	nocol-4.2b6
CATEGORIES=	net
MASTER_SITES= 	ftp://ftp.navya.com/pub/vikas/

MAINTAINER=	packages@netbsd.org

USE_PERL=	yes

INSTALL_TARGET=	install root

.ifndef FQDN
FQDN!=		/usr/sbin/host `/bin/hostname` | /usr/bin/awk '{ print $$1; exit }'
.endif

post-patch:
	@${SED} -e 's|@prefix@|${PREFIX}|g' -e 's|@FQDN@|${FQDN}|g' ${FILESDIR}/answers > ${WRKSRC}/answers

do-configure:
	(cd ${WRKSRC}; ./Configure < answers)

.include "../../mk/bsd.pkg.mk"
