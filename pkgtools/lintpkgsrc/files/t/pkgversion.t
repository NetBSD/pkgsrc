# $NetBSD: pkgversion.t,v 1.1 2022/07/30 10:11:45 rillig Exp $
use strict;
use warnings;
use Test;

BEGIN { plan tests => 5; }

$ENV{'TESTING_LINTPKGSRC'} = 'yes';
require('../lintpkgsrc.pl');

ok(pkgversioncmp('3.4', '<', '3.4'), '');
ok(pkgversioncmp('3.4', '<=', '3.4'), 1);
ok(pkgversioncmp('3.4', '>=', '3.4.0.0.0'), 1);
ok(pkgversioncmp('3.4nb13', '>=', '3.4'), 1);
ok(pkgversioncmp('3.4nb13', '<', '3.4'), '');
