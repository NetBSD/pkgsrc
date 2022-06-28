# $NetBSD: Makefile,v 1.28 2022/06/28 11:35:20 wiz Exp $

DISTNAME=	sitescooper-2.2.8
PKGREVISION=	13
CATEGORIES=	net comms
MASTER_SITES=	http://sitescooper.cx/released/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sitescooper.cx/
COMMENT=	Retrieve stories from websites and convert to Palm readable format

DEPENDS+=	p5-libwww>=5.46:../../www/p5-libwww
DEPENDS+=	pilotmgr-[0-9]*:../../comms/pilotmgr

USE_TOOLS+=	perl:run
NO_BUILD=	yes

CONF_FILES+=	${PREFIX}/share/examples/sitescooper/sitescooper.cf \
		${PREFIX}/etc/sitescooper.cf

INSTALLATION_DIRS=	bin etc ${PKGMANDIR}/man1 share/doc/sitescooper \
			share/examples/sitescooper share/sitescooper/lib

do-configure:
.for file in sitescooper rss-to-site subs-to-site
	cd ${WRKSRC} && \
	${SED} -e 's:/usr/bin/perl:${PERL5}:g' <${file}.pl >${file}
.endfor
.for file in lib/Scoop.pm sitescooper.cf
	cd ${WRKSRC} && ${CP} ${file} ${file}.orig && \
	${SED} -e 's:/etc:${PREFIX}/etc:g' \
	       -e 's!^# SitescooperDir: /where/sitescooper/is/installed!SitescooperDir: ${PREFIX}/share/sitescooper!' \
		<${file}.orig >${file} && \
	${RM} ${file}.orig
.endfor
	${RM} -rf `${FIND} ${WRKSRC}/* -name CVS -type d -print`

do-install:
.for file in sitescooper rss-to-site subs-to-site
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/${file}.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${file}.1
.endfor
	${CP} -R ${WRKSRC}/site_samples ${DESTDIR}${PREFIX}/share/sitescooper
	${CP} -R ${WRKSRC}/lib/* ${DESTDIR}${PREFIX}/share/sitescooper/lib
	${CP} -R ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/sitescooper
.for file in CHANGES.txt README.txt sitescooper.spec
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/share/doc/sitescooper
.endfor
	${INSTALL_DATA} ${WRKSRC}/sitescooper.cf \
	    ${DESTDIR}${PREFIX}/share/examples/sitescooper/sitescooper.cf

.include "../../mk/bsd.pkg.mk"
