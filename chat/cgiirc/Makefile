# $NetBSD: Makefile,v 1.2 2005/01/19 21:27:39 adrianp Exp $

DISTNAME=	cgiirc-0.5.5
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cgiirc/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://cgiirc.sourceforge.net/
COMMENT=	Access IRC from a web browser

NO_BUILDLINK=	YES
USE_PERL5=	run
NO_BUILD=	YES
USE_PKGINSTALL=	YES

SUBST_CLASSES=		config
SUBST_STAGE.config=	post-patch
SUBST_FILES.config= 	${WRKDIR}/cgiirc.conf
SUBST_SED.config=	-e "s|@CGIIRC@|${CGIIRC}|g"
SUBST_MESSAGE.config=	"Setting defaults in configuration files."

BUILD_DEFS+=	USE_INET6

CONF_FILES=	${PREFIX}/share/examples/cgiirc/cgiirc.conf \
			${PKG_SYSCONFDIR}/cgiirc.conf
CONF_FILES+=	${PREFIX}/share/examples/cgiirc/cgiirc.config \
			${CGIIRC}/cgiirc.config

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
DEPENDS+=	p5-INET6-*:../../net/p5-INET6
.endif

REPLACE_PERL=	client-perl.cgi irc.cgi nph-irc.cgi docs/decode.pl \
		docs/identd.pl viewconnects.pl modules/parse.pl \
		interfaces/interface-make/make-js-interfaces.pl

DOCFILES=	identd.xinetd decode.pl identd.pl viewconnects.pl
EGFILES=	cgiirc.config.full client.c ipaccess.example
CGIIRC=		${PREFIX}/share/cgiirc

pre-patch:
	@${CP} ${FILESDIR}/cgiirc.conf ${WRKDIR}/cgiirc.conf

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cgiirc
	${INSTALL_DATA_DIR} ${CGIIRC}
	${INSTALL_DATA_DIR} ${CGIIRC}/formats
	${INSTALL_DATA_DIR} ${CGIIRC}/images
	${INSTALL_DATA_DIR} ${CGIIRC}/images/taras
	${INSTALL_DATA_DIR} ${CGIIRC}/interfaces
	${INSTALL_DATA_DIR} ${CGIIRC}/interfaces/interface-make
	${INSTALL_DATA_DIR} ${CGIIRC}/modules
	${INSTALL_DATA_DIR} ${CGIIRC}/modules/IRC
	${INSTALL_DATA_DIR} ${CGIIRC}/modules/IRC/Channel
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cgiirc

	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cgiirc
.	for f in ${DOCFILES}
		${INSTALL_DATA} ${WRKSRC}/docs/${f} \
			${PREFIX}/share/examples/cgiirc/${f}
.	endfor
.	undef f
	${INSTALL_DATA} ${WRKSRC}/cgiirc.config ${PREFIX}/share/examples/cgiirc
	${INSTALL_DATA} ${WRKDIR}/cgiirc.conf ${PREFIX}/share/examples/cgiirc
.	for f in ${EGFILES}
		${INSTALL_DATA} ${WRKSRC}/${f} \
			${PREFIX}/share/examples/cgiirc/${f}
.	endfor
.	undef f
	${INSTALL_SCRIPT} ${WRKSRC}/*.cgi ${CGIIRC}
	${INSTALL_DATA} ${WRKSRC}/formats/* ${CGIIRC}/formats/
	${INSTALL_DATA} ${WRKSRC}/images/*.gif ${CGIIRC}/images/
	${INSTALL_DATA} ${WRKSRC}/images/*.wav ${CGIIRC}/images/
	${INSTALL_DATA} ${WRKSRC}/images/*.ico ${CGIIRC}/images/
	${INSTALL_DATA} ${WRKSRC}/images/taras/*.gif ${CGIIRC}/images/taras
	${INSTALL_DATA} ${WRKSRC}/interfaces/*.pm ${CGIIRC}/interfaces/
	${INSTALL_DATA} ${WRKSRC}/interfaces/*.css ${CGIIRC}/interfaces/
	${INSTALL_DATA} ${WRKSRC}/interfaces/interface-make/*.pm \
		${CGIIRC}/interfaces/interface-make/
	${INSTALL_SCRIPT} ${WRKSRC}/interfaces/interface-make/*.pl \
		${CGIIRC}/interfaces/interface-make/
	${INSTALL_DATA} ${WRKSRC}/modules/*.pm ${CGIIRC}/modules/
	${INSTALL_SCRIPT} ${WRKSRC}/modules/*.pl ${CGIIRC}/modules/
	${INSTALL_DATA} ${WRKSRC}/modules/IRC/*.pm ${CGIIRC}/modules/IRC/
	${INSTALL_DATA} ${WRKSRC}/modules/IRC/Channel/*.pm \
		${CGIIRC}/modules/IRC/Channel/

.include "../../mk/bsd.pkg.mk"
