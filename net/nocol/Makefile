# $NetBSD: Makefile,v 1.2 1998/08/04 14:48:19 agc Exp $
#

DISTNAME=	nocol-4.2beta6
PKGNAME=	nocol-4.2b6
CATEGORIES=	net
MASTER_SITES= 	ftp://ftp.navya.com/pub/vikas/

MAINTAINER=	packages@netbsd.org

USE_PERL=	yes

INSTALL_TARGET=	install root

post-patch:
	@(hostname=`/bin/hostname`;					\
	fqdn=`/usr/sbin/host $$hostname | /usr/bin/awk '{ print $$1; exit }'`; \
	${SED} -e 's|@prefix@|${PREFIX}|g' -e "s|@FQDN@|$$fqdn|g" 	\
			${FILESDIR}/answers > ${WRKSRC}/answers)

do-configure:
	(cd ${WRKSRC}; ./Configure < answers)

.include "../../mk/bsd.pkg.mk"
