# $NetBSD: Makefile,v 1.2 2023/07/06 09:38:13 wiz Exp $

DISTNAME=	info2man_1.1.orig
PKGNAME=	${DISTNAME:S,_1.1.orig,-1.1,}
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	https://deb.debian.org/debian/pool/main/i/info2man/
DIST_SUBDIR=	info2man

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20040625210730/http://www.cskk.ezoshosting.com/cs/css/info2pod.html
COMMENT=	Wrapper for info2pod to convert info files in man format
LICENSE=	original-bsd # no license

NO_BUILD=		yes
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin
INFO2MAN_PM+=		Pathname.pm Misc.pm Math.pm
INFO2MAN_PM+=		Sink.pm IO.pm GNUInfo.pm Source.pm
INFO2MAN_PM+=		Object.pm DEBUG.pm
REPLACE_PERL=		info2pod
REPLACE_PERL+=		cs/*.pm
REPLACE_PERL+=		cs/*/*.pm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/info2man ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/info2pod ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PERL5_INSTALLVENDORLIB}/cs
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PERL5_INSTALLVENDORLIB}/cs/GNUInfo/

	cd ${WRKSRC}/cs && for file in ${INFO2MAN_PM}; do \
		${INSTALL_SCRIPT} "$${file}" ${DESTDIR}${PERL5_INSTALLVENDORLIB}/cs; \
	done

	${INSTALL_SCRIPT} ${WRKSRC}/cs/GNUInfo/Node.pm ${DESTDIR}${PERL5_INSTALLVENDORLIB}/cs/GNUInfo

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
