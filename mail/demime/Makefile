# $NetBSD: Makefile,v 1.19 2005/12/29 06:21:48 jlam Exp $
#

DISTNAME=	demime-1.1d
CATEGORIES=	mail textproc
MASTER_SITES=	${MASTER_SITE_LOCAL:=${PKGNAME_NOREV}/} \
		http://majordomo.squawk.com/njs/demime/ \
		http://scifi.squawk.com/
DISTFILES=	${DISTNAME:S/-/./} \
		demime_junkmail.cf

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://scifi.squawk.com/demime.html
COMMENT=	Tool to scrub mime from mailing lists

DEPENDS+=       p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=       p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=       p5-HTML-Format-[0-9]*:../../www/p5-HTML-Format
DEPENDS+=       p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree

DIST_SUBDIR=	${PKGNAME_NOREV}
USE_TOOLS+=	perl:run pod2man

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/demime_junkmail.cf ${PKG_SYSCONFDIR}/demime_junkmail.cf

INSTALLATION_DIRS=	bin man/man1

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME:S/-/./} ${WRKSRC}/demime.stable

do-build:
	${SED} -e 's|/usr/lib/majordomo/demime_junkmail.cf|${PKG_SYSCONFDIR}/demime_junkmail.cf|g' \
	       -e 's|/usr/bin/perl|${PERL5}|g' \
	       ${WRKSRC}/demime.stable >${WRKSRC}/demime
	${POD2MAN} ${WRKSRC}/demime > ${WRKSRC}/demime.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/demime ${PREFIX}/bin/demime
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/demime_junkmail.cf ${EGDIR}
	${INSTALL_MAN} ${WRKSRC}/demime.1 ${PREFIX}/man/man1/demime.1

.include "../../mk/bsd.pkg.mk"
