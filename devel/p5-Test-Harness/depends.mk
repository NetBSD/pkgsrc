# $NetBSD: depends.mk,v 1.2 2004/06/12 04:01:45 grant Exp $

# perl58>=5.8.3 includes Test::Harness, so allow it to satisfy this
# dependency.
DEPENDS+=	{perl{,-thread}>=5.8.3,p5-Test-Harness-[0-9]*}:../../devel/p5-Test-Harness
