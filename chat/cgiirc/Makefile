# $NetBSD: Makefile,v 1.19 2012/10/03 00:02:34 asau Exp $

DISTNAME=	cgiirc-0.5.10
#PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	http://cgiirc.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cgiirc.org/
COMMENT=	Access IRC from a web browser
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run
NO_BUILD=	YES

CONF_FILES=	${PREFIX}/share/examples/cgiirc/cgiirc.conf \
			${PKG_SYSCONFDIR}/cgiirc.conf
CONF_FILES+=	${PREFIX}/share/examples/cgiirc/cgiirc.config \
			${CGIIRC}/cgiirc.config

PKG_OPTIONS_VAR=	PKG_OPTIONS.cgiirc
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
DEPENDS+=	p5-IO-Socket-INET6-[0-9]*:../../net/p5-IO-Socket-INET6
.endif

REPLACE_PERL+=	client-perl.cgi irc.cgi nph-irc.cgi docs/decode.pl \
		docs/identd.pl docs/viewconnects.pl modules/parse.pl \
		interfaces/interface-make/make-js-interfaces.pl

DOCFILES=	identd.xinetd decode.pl identd.pl viewconnects.pl
EGFILES=	cgiirc.config.full client.c ipaccess.example
CGIIRC=		${PREFIX}/share/cgiirc

do-configure:
	${SED} -e "s|@CGIIRC@|${CGIIRC}|g" ${FILESDIR}/cgiirc.conf	\
		> ${WRKDIR}/cgiirc.conf

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/cgiirc
	${INSTALL_DATA_DIR} ${DESTDIR}${CGIIRC}
	${INSTALL_DATA_DIR} ${DESTDIR}${CGIIRC}/formats
	${INSTALL_DATA_DIR} ${DESTDIR}${CGIIRC}/images
	${INSTALL_DATA_DIR} ${DESTDIR}${CGIIRC}/images/taras
	${INSTALL_DATA_DIR} ${DESTDIR}${CGIIRC}/interfaces
	${INSTALL_DATA_DIR} ${DESTDIR}${CGIIRC}/interfaces/interface-make
	${INSTALL_DATA_DIR} ${DESTDIR}${CGIIRC}/modules
	${INSTALL_DATA_DIR} ${DESTDIR}${CGIIRC}/modules/IRC
	${INSTALL_DATA_DIR} ${DESTDIR}${CGIIRC}/modules/IRC/Channel
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/cgiirc

	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/cgiirc
.	for f in ${DOCFILES}
		${INSTALL_DATA} ${WRKSRC}/docs/${f} \
			${DESTDIR}${PREFIX}/share/examples/cgiirc/${f}
.	endfor
	${INSTALL_DATA} ${WRKSRC}/cgiirc.config \
		${DESTDIR}${PREFIX}/share/examples/cgiirc
	${INSTALL_DATA} ${WRKDIR}/cgiirc.conf \
		${DESTDIR}${PREFIX}/share/examples/cgiirc
.	for f in ${EGFILES}
		${INSTALL_DATA} ${WRKSRC}/${f} \
			${DESTDIR}${PREFIX}/share/examples/cgiirc/${f}
.	endfor
	${INSTALL_SCRIPT} ${WRKSRC}/*.cgi ${DESTDIR}${CGIIRC}
	${INSTALL_DATA} ${WRKSRC}/formats/* ${DESTDIR}${CGIIRC}/formats/
	${INSTALL_DATA} ${WRKSRC}/images/*.gif ${DESTDIR}${CGIIRC}/images/
	${INSTALL_DATA} ${WRKSRC}/images/*.wav ${DESTDIR}${CGIIRC}/images/
	${INSTALL_DATA} ${WRKSRC}/images/*.ico ${DESTDIR}${CGIIRC}/images/
	${INSTALL_DATA} ${WRKSRC}/images/taras/*.gif \
		${DESTDIR}${CGIIRC}/images/taras
	${INSTALL_DATA} ${WRKSRC}/interfaces/*.pm ${DESTDIR}${CGIIRC}/interfaces/
	${INSTALL_DATA} ${WRKSRC}/interfaces/*.css ${DESTDIR}${CGIIRC}/interfaces/
	${INSTALL_DATA} ${WRKSRC}/interfaces/interface-make/*.pm \
		${DESTDIR}${CGIIRC}/interfaces/interface-make/
	${INSTALL_SCRIPT} ${WRKSRC}/interfaces/interface-make/*.pl \
		${DESTDIR}${CGIIRC}/interfaces/interface-make/
	${INSTALL_DATA} ${WRKSRC}/modules/*.pm ${DESTDIR}${CGIIRC}/modules/
	${INSTALL_SCRIPT} ${WRKSRC}/modules/*.pl ${DESTDIR}${CGIIRC}/modules/
	${INSTALL_DATA} ${WRKSRC}/modules/IRC/*.pm ${DESTDIR}${CGIIRC}/modules/IRC/
	${INSTALL_DATA} ${WRKSRC}/modules/IRC/Channel/*.pm \
		${DESTDIR}${CGIIRC}/modules/IRC/Channel/

.include "../../mk/bsd.pkg.mk"
