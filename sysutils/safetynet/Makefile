# $NetBSD: Makefile,v 1.21 2022/06/28 11:36:05 wiz Exp $
#

DISTNAME=	safetynet-1.15
PKGREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	# http://www.unixpimps.org/safetynet/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.unixpimps.org/safetynet/
COMMENT=	Safetynet is a perl script intended to monitor system services

WRKSRC=		${WRKDIR}
NO_BUILD=	YES
USE_TOOLS+=	perl:run

INSTALLATION_DIRS=	bin etc share/doc/safetynet

post-patch:
	${SED}	-e "s,/etc/safetynet.conf,${PREFIX}/etc/safetynet.conf,g" \
		-e "s,/bin/mail,/usr/bin/mail,g"			\
		-e "s,ps -Af,ps ax,g"					\
		-e "s,/usr/bin/perl,${LOCALBASE}/bin/perl,g"		\
		${WRKSRC}/safetynet > ${WRKSRC}/safetynet.done
	${MV} -f ${WRKSRC}/safetynet.done ${WRKSRC}/safetynet
	${SED}	-e "s,/usr/local/apache/bin/apachectl,${LOCALBASE}/sbin/apachectl,g" \
		-e "s,/usr/local,${PREFIX},g"				\
		${WRKSRC}/safetynet.conf > ${WRKSRC}/safetynet.conf.done
	${MV} ${WRKSRC}/safetynet.conf.done ${WRKSRC}/safetynet.conf

do-install:
	${INSTALL_SCRIPT} -m 700 ${WRKSRC}/safetynet ${DESTDIR}${PREFIX}/bin/safetynet
	${INSTALL_DATA} -m 600 ${WRKSRC}/safetynet.conf ${DESTDIR}${PREFIX}/etc/safetynet.conf.sample
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/safetynet/README

.include "../../mk/bsd.pkg.mk"
