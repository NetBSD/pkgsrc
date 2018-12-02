package intqa

// XXX: It might be nice to check all comments of the form "See XYZ"
// to see whether XYZ actually exists. The scope should be the current type,
// then the current package, then a package-qualified identifier.
// As if there were a "_ = XYZ" at the beginning of the function.

// XXX: All methods should be defined in the same file as their receiver type.
// If that is not possible, there should only be a small list of exceptions.

// XXX: All tests should be in the same order as their corresponding elements in the
// main code.

// XXX: All tests for a single testee should be grouped together.

// XXX: If there is a constructor for a type, only that constructor may be used
// for constructing objects. All other forms (var x Type; x := &Type{}) should be forbidden.
