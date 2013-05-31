# $NetBSD: Makefile,v 1.6 2013/05/31 12:39:55 wiz Exp $
#

DISTNAME=	percona-toolkit-2.1.7
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://www.percona.com/downloads/percona-toolkit/${PKGVERSION_NOREV}/

MAINTAINER=	msporleder@gmail.com
HOMEPAGE=	http://www.percona.com/software/percona-toolkit/
COMMENT=	Advanced command-line tools for open-source databases (MySQL)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl

REPLACE_PERL+=	bin/*
CHECK_INTERPRETER_SKIP+=	*pt-ioprofile
CHECK_INTERPRETER_SKIP+=	*pt-mysql-summary
CHECK_INTERPRETER_SKIP+=	*pt-pmp
CHECK_INTERPRETER_SKIP+=	*pt-sift
CHECK_INTERPRETER_SKIP+=	*pt-stalk

DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes
DEPENDS+=	bash-[0-9]*:../../shells/bash

PERL5_PACKLIST=	auto/percona-toolkit/.packlist
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
