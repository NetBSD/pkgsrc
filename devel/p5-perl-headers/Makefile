# $NetBSD: Makefile,v 1.37 2011/08/14 12:26:50 obache Exp $

DISTNAME=		p5-perl-headers
PKGNAME=		${DISTNAME}-${OS_VERSION}
PKGREVISION=		6
SVR4_PKGNAME=		p5plh
CATEGORIES=		devel perl5
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.perl.com/language/index.html
COMMENT=		Perl header files

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

WRKSRC=			${WRKDIR}
PERL5_PACKLIST=		.packlist.h2ph

NO_CONFIGURE=		yes
OSVERSION_SPECIFIC=	yes

do-build:
	${MKDIR} ${WRKSRC}/h2ph
	${RM} -f ${WRKSRC}/h2ph_log ${WRKSRC}/packlist
	( cd "/usr/include" && \
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
