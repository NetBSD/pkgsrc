# Before `make install' is performed this script should be runnable with
# `make test'. After `make install' it should work as `perl Dewey.t'

#########################

# change 'tests => 1' to 'tests => last_test_to_print';

use Test::More tests => 5;
BEGIN { use_ok('pkgsrc::Dewey') };

#########################

# Insert your test code below, the Test::More module is use()ed here so read
# its man page ( perldoc Test::More ) for help writing this test script.

ok(dewey_cmp("1.0", "<", "2.0") > 0, 'dewey_cmp result incorrect');
ok(dewey_cmp("1.0", "a", "2.0") == -1, 'incorrect operator');
ok(dewey_match("foo<1.0", "foo-1.0beta1"), 'beta');
is(dewey_match("foo<1.0alpha1", "foo-1.0beta1"), 0, 'alpha');
