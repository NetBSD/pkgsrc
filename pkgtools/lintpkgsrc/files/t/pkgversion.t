# $NetBSD: pkgversion.t,v 1.2 2022/07/30 17:06:29 rillig Exp $
use strict;
use warnings;
use Test;

BEGIN { plan tests => 5; }

require('../lintpkgsrc.pl');

ok(pkgversioncmp('3.4', '<', '3.4'), '');
ok(pkgversioncmp('3.4', '<=', '3.4'), 1);
ok(pkgversioncmp('3.4', '>=', '3.4.0.0.0'), 1);
ok(pkgversioncmp('3.4nb13', '>=', '3.4'), 1);
ok(pkgversioncmp('3.4nb13', '<', '3.4'), '');
