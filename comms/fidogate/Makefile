# $NetBSD: Makefile,v 1.1 1998/07/16 17:47:14 tv Exp $
#

DISTNAME=	fidogate-4.2.9
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.fido.de/pub/fidogate/

MAINTAINER=	tv@netbsd.org	# aka "Todd Vierling" @ 1:396/1.5

BUILD_DEPENDS=	${PREFIX}/bin/libtool:../../devel/libtool

USE_GMAKE=	yes
USE_GTEXINFO=	yes
USE_PERL5=	yes
MAKE_ENV=	LIBTOOL=${PREFIX}/bin/libtool
WRKSRC=		${WRKDIR}/fidogate

pre-install:
	${INSTALL_DATA_DIR} -m 0755 ${PREFIX}/lib/fidogate

post-install:
	${INSTALL_DATA_DIR} \
		${PREFIX}/share/fidogate \
		${PREFIX}/share/fidogate/inn \
		${PREFIX}/share/fidogate/nodelist \
		${PREFIX}/share/fidogate/scripts \
		${PREFIX}/share/fidogate/sendmail
	cd ${WRKSRC}/scripts/inn && \
		${INSTALL_DATA} send-ffx send-fidogate viaffx ${PREFIX}/share/fidogate/inn/
	cd ${WRKSRC}/scripts/nodelist && \
		${INSTALL_DATA} latest nl-2hosts nl-2routing nl-autoupd \
				nl-check nl-del nl-diff nl-html nl-isdn \
				nl-print template.html ${PREFIX}/share/fidogate/nodelist/
	cd ${WRKSRC}/scripts/outbound && \
		${INSTALL_DATA} out-freq out-ls out-manip out-rm0 out-rmbsy ${PREFIX}/share/fidogate/scripts/
	cd ${WRKSRC}/scripts/run && \
		${INSTALL_DATA} run1 run2 runffx runpoll ${PREFIX}/share/fidogate/scripts/
	cd ${WRKSRC}/sendmail/mailer && \
		${INSTALL_DATA} ffx.m4 ftn.m4 ${PREFIX}/share/fidogate/sendmail/
	${INSTALL_DATA} ${WRKSRC}/scripts/maintenance/rc.fidogate ${PREFIX}/etc/rc.d/fidogate.sh

.include "../../mk/bsd.pkg.mk"
