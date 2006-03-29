# $NetBSD: Makefile,v 1.12 2006/03/29 01:28:46 gavan Exp $

DISTNAME=		sqlrelay-0.37
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sqlrelay/}

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://sqlrelay.sourceforge.net/
COMMENT=		Enables pooling and sharing of database connections

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES

PERL5_PACKLIST=		auto/SQLRelay/Connection/.packlist
PERL5_PACKLIST+=	auto/SQLRelay/Cursor/.packlist
PERL5_PACKLIST+=	auto/DBD/SQLRelay/.packlist
CONFIGURE_ARGS+=	--with-perl-site-arch=${PERL5_INSTALLVENDORARCH:Q}
CONFIGURE_ARGS+=	--with-perl-site-lib=${PERL5_INSTALLVENDORLIB:Q}
CONFIGURE_ARGS+=	--with-perl-install-man3-dir=${PERL5_INSTALLVENDORMAN3DIR:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
MAKE_ENV+=		EXAMPLESDIR=${EGDIR:Q}

PKG_SYSCONFSUBDIR=	sqlrelay
EGDIR=			${PREFIX}/share/examples/sqlrelay

CONF_FILES+=		${EGDIR}/sqlrelay.conf.example \
			${PKG_SYSCONFDIR}/sqlrelay.conf
CONF_FILES+=		${EGDIR}/sqlrelay.dtd \
			${PKG_SYSCONFDIR}/sqlrelay.dtd

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/init/netbsd/rc.d/sqlrelay ${PREFIX}/share/examples/rc.d/sqlrelay

RCD_SCRIPTS+=		sqlrelay

.include "options.mk"

.include "../../devel/rudiments/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/perl5/packlist.mk"
.include "../../lang/perl5/vars.mk"
.include "../../mk/bsd.pkg.mk"
