# $NetBSD: Makefile,v 1.1.1.1 2000/06/07 16:48:56 rh Exp $
#

DISTNAME=	sitescooper-2.2.8
CATEGORIES=	net comms
MASTER_SITES=	http://sitescooper.cx/released/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://sitescooper.cx/

DEPENDS+=	p5-libwww>=5.46:../../www/p5-libwww
DEPENDS+=	pilotmgr-*:../../comms/pilotmgr

USE_PERL5=	YES
NO_BUILD=	YES

do-configure:
.for file in sitescooper rss-to-site subs-to-site
	cd ${WRKSRC} && \
	${SED} -e 's:/usr/bin/perl:${PREFIX}/bin/perl:g' <${file}.pl >${file}
.endfor
.for file in lib/Scoop.pm sitescooper.cf
	cd ${WRKSRC} && ${CP} ${file} ${file}.orig && \
	${SED} -e 's:/etc:${PREFIX}/etc:g' \
	       -e 's!^# SitescooperDir: /where/sitescooper/is/installed!SitescooperDir: ${PREFIX}/share/sitescooper!' \
		<${file}.orig >${file} && \
	${RM} ${file}.orig
.endfor
	${RM} -rf `${FIND} ${WRKSRC}/* -name CVS -type d`

do-install:
.for file in sitescooper rss-to-site subs-to-site
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/${file}.man ${PREFIX}/man/man1/${file}.1
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/sitescooper/lib
	${CP} -R ${WRKSRC}/site_samples ${PREFIX}/share/sitescooper
	${CP} -R ${WRKSRC}/lib/* ${PREFIX}/share/sitescooper/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sitescooper
	${CP} -R ${WRKSRC}/doc/* ${PREFIX}/share/doc/sitescooper
.for file in CHANGES.txt README.txt sitescooper.spec
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/sitescooper
.endfor
	${INSTALL_DATA} ${WRKSRC}/sitescooper.cf ${PREFIX}/etc/sitescooper.cf.sample
	if [ ! -f ${PREFIX}/etc/sitescooper.cf ]; then \
		${INSTALL_DATA} ${WRKSRC}/sitescooper.cf ${PREFIX}/etc ; \
	fi

.include "../../mk/bsd.pkg.mk"
