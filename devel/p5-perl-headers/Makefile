# $NetBSD: Makefile,v 1.51 2019/08/11 13:20:48 wiz Exp $

DISTNAME=		p5-perl-headers
PKGNAME=		${DISTNAME}-${OS_VERSION}
PKGREVISION=		14
CATEGORIES=		devel perl5
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		https://www.perl.com/language/index.html
COMMENT=		Perl header files

USE_TOOLS+=	pax

WRKSRC=			${WRKDIR}
PERL5_PACKLIST=		.packlist.h2ph

NO_CONFIGURE=		yes
OSVERSION_SPECIFIC=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" && exists(${OSX_SDK_PATH}/usr/include)
USR_INCLUDE=		${OSX_SDK_PATH}/usr/include
.else
USR_INCLUDE=		/usr/include
.endif

do-build:
	${MKDIR} ${WRKSRC}/h2ph
	${RM} -f ${WRKSRC}/h2ph_log ${WRKSRC}/packlist
	( cd "${USR_INCLUDE}" && \
	  ${BUILDLINK_PREFIX.perl}/bin/h2ph -d ${WRKSRC}/h2ph -r -l . ) \
		> ${WRKSRC}/h2ph_log
	( ${ECHO} "${PERL5_INSTALLVENDORARCH}/_h2ph_pre.ph" && \
	  ${CAT} ${WRKSRC}/h2ph_log \
		| ${GREP} -- "->" \
		| ${SED} -e 's,.*\./,${PERL5_INSTALLVENDORARCH}/,g' ) \
		| ${SORT} -u \
		> ${WRKSRC}/packlist

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PERL5_INSTALLVENDORARCH}
	cd ${WRKSRC}/h2ph/ && pax -rw . ${DESTDIR}${PERL5_INSTALLVENDORARCH}
	${INSTALL_DATA} ${WRKSRC}/packlist ${DESTDIR}${PERL5_INSTALLVENDORARCH}/${PERL5_PACKLIST}
	${SED} 's,^,${DESTDIR},' < ${DESTDIR}${PERL5_INSTALLVENDORARCH}/${PERL5_PACKLIST} | ${XARGS} ${CHMOD} a-w
	${SED} 's,^,${DESTDIR},' < ${DESTDIR}${PERL5_INSTALLVENDORARCH}/${PERL5_PACKLIST} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${DESTDIR}${PERL5_INSTALLVENDORARCH} -type d -print \
		-exec ${CHMOD} ${PKGDIRMODE} {} \;

# empty do-nothing to override module.mk TEST_TARGET
do-test:

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
