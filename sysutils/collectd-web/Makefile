# $NetBSD: Makefile,v 1.4 2022/06/28 11:35:54 wiz Exp $

DISTNAME=	collectd-web-0.4.1
PKGREVISION=	3
CATEGORIES=	sysutils
GITHUB_PROJECT=	collectd-web
MASTER_SITES=	${MASTER_SITE_GITHUB:=httpdss/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/httpdss/collectd-web
COMMENT=	Web interface for Collectd
LICENSE=	gnu-gpl-v2

DEPENDS+=	fcgiwrap>=1.1.0:../../www/fcgiwrap
DEPENDS+=	spawn-fcgi>=1.6.3:../../www/spawn-fcgi
DEPENDS+=	p5-HTTP-Parser>=0.06:../../www/p5-HTTP-Parser
DEPENDS+=	p5-JSON>=2.94:../../converters/p5-JSON
DEPENDS+=	p5-RRD-Simple>=1.44:../../databases/p5-RRD-Simple
DEPENDS+=	p5-CGI>=4.36:../../www/p5-CGI
#DEPENDS+=	cgic>=2.02:../../www/cgic
#DEPENDS+=	fcgi>=2.4.0:../../www/fcgi

NO_BUILD=		yes
USE_TOOLS+=		pax perl:run
REPLACE_PERL+=		cgi-bin/*.pl
REPLACE_PERL+=		cgi-bin/*.cgi
REPLACE_SH+=		check_deps.sh
REPLACE_PYTHON+=	runserver.py

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	# none

do-configure:
	# empty target is needed, otherwise REPLACE_* do not happen

do-install:
	cd ${WRKSRC} && pax -rw -pp . ${DESTDIR}${PREFIX}/share/collectd-web

.include "../../lang/perl5/module.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
