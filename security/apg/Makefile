# $NetBSD: Makefile,v 1.27 2019/08/11 13:22:44 wiz Exp $
#

DISTNAME=	apg-2.3.0b
PKGREVISION=	7
CATEGORIES=	security
#MASTER_SITES=	http://www.adel.nursat.kz/apg/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.adel.nursat.kz/apg/
COMMENT=	Tool set for random password generation
LICENSE=	modified-bsd

MAKE_ENV+=	FLAGS=${CFLAGS:M*:Q} INSTALL_PREFIX=${DESTDIR:Q}${PREFIX:Q}

USE_TOOLS+=	perl:run
REPLACE_PERL=	perl/apgcli.pl

OPSYSVARS+=	APG_CS_CLIBS
APG_CS_CLIBS.Linux+=	-lnsl
APG_CS_CLIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	APG_CS_CLIBS=${APG_CS_CLIBS:Q}

INSTALLATION_DIRS+=	bin sbin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8

.include "options.mk"

.if ${OPSYS} == "Darwin" || ${OPSYS} == "OpenBSD"
BUILDLINK_TRANSFORM+=	l:crypt:crypto
.endif

post-extract:
	${CHMOD} -R u+w ${WRKSRC}
	${RM} -f ${WRKSRC}/INSTALL

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/perl/apgcli.pl ${DESTDIR}${PREFIX}/bin/apgcli

.include "../../mk/bsd.pkg.mk"
